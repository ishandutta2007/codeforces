#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); coutcout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef long double ld;

const int arr=2e5;

vector<int> vec[arr];
string st[arr];
int cnt[1000],good[arr],cnt1[1000];

signed main()
{
    int k,n;
    cin>>k>>n;

    for (int i=1;i<=k;i++)
        cin>>st[i];

    if (k==1)
    {
        swap(st[1][0],st[1][1]);
        cout<<st[1];
        return(0);
    }

    /*for (auto i:st[1])
        cnt1[i]++;
*/


    for (int i=2;i<=k;i++)
    {
        for (int j=0;j<n;j++)
            if (st[1][j]!=st[i][j])
            vec[i].pb(j);
        if (vec[i].size()>4)
        {
            cout<<-1;
            return(0);
        }

        for (int j=0;j<n;j++)
            cnt[st[i][j]]++;

        for (int j=0;j<=500;j++)
        {
            if (cnt[j]>=2)
                good[i]=1;
            /*if (cnt[j]!=cnt1[j])
            {
                cout<<-1;
                return(0);
            }*/
        }


        for (int j=0;j<n;j++)
            cnt[st[i][j]]--;
    }

    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
        {
            bool ch=1;
            swap(st[1][i],st[1][j]);

            for (int l=2; l<=k && ch;l++)
            {
                int pred=-1;
                int last=-1;
                for (auto pos:vec[l])
                    if (st[1][pos]!=st[l][pos])
                    {
                        if (pred==-1)
                            pred=pos; else
                        if (last==-1)
                            last=pos; else
                            {
                                ch=0;
                                break;
                            }
                    }


                //cout<<last<<' '<<pred<<' '<<st[1]<<'\n';


                if (st[1][i]!=st[l][i])
                {
                    if (!(i==last || i==pred))
                    if (pred==-1)
                            pred=i; else
                        if (last==-1)
                            last=i; else
                            {
                                ch=0;
                                break;
                            }
                }

                if (st[1][j]!=st[l][j])
                {

                    if (!(j==last || j==pred))
                    if (pred==-1)
                            pred=j; else
                        if (last==-1)
                            last=j; else
                            {
                                ch=0;
                                break;
                            }
                }

                //cout<<last<<' '<<pred<<' '<<st[1]<<'\n';

                if (ch)
                {
                    if (pred==-1)
                    {
                        ch&=good[l];
                    } else
                    if (last!=-1)
                    {
                        ch&=(st[1][last]==st[l][pred] && st[1][pred]==st[l][last]);
                    } else
                    ch=0;
                }

              //  cout<<l<<' '<<ch<<'\n';
            }
            if (ch)
            {
                cout<<st[1];
                return(0);
            }
            swap(st[1][i],st[1][j]);

        }

    cout<<-1;
}