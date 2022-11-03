#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ull
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int last=2;
int n;

int siz=30;

int a[2000][2000];
int s=3;

vector<int> vec;

void make_(int u, int cnt)
{
    if (cnt==0)
        return;
    int len=1;
    int pred1=1;
    int pred2=1;
    int pred3=1;
    for (int i=1;i<=u;i++)
    {
        a[pred1][last+1]=1;
        a[pred2][last+2]=1;
        a[pred2][last+1]=1;
        a[pred1][last+2]=1;
        a[pred1][last+3]=1;
        a[pred2][last+3]=1;
        a[pred3][last+1]=1;
        a[pred3][last+2]=1;
        a[pred3][last+3]=1;
        pred1=last+1;
        pred2=last+2;
        pred3=last+3;
        last+=3;
        len++;
    }

    if (cnt==1)
    {
        if (u<vec.size()+2)
        {
            a[pred1][last+1]=1;
            a[pred2][last+1]=1;
            a[pred3][last+1]=1;
            last++;
            for (int i=u+1;i<vec.size()+2;i++)
            {
                a[last][last+1]=1;
                last++;
            }
            a[last][2]=1;
        }
        if (u==vec.size()+2)
        {
            a[pred1][2]=1;
            a[pred2][2]=1;
            a[pred3][2]=1;
        }
    } else
    {
        //cout<<'!';
        if (u<vec.size()+1)
        {
            //cout<<'@';
            a[pred1][last+1]=1;
            a[pred2][last+1]=1;
            a[pred3][last+1]=1;
            last++;
            for (int i=u+1;i<vec.size()+1;i++)
            {
                a[last][last+1]=1;
                last++;
            }
            a[last][last+1]=1;
            a[last][last+2]=1;
            a[last+1][2]=1;
            a[last+2][2]=1;
            last+=2;
        }
        if (u==vec.size()+1)
        {
            a[pred1][last+1]=1;
            a[pred2][last+1]=1;
            a[pred3][last+1]=1;
            a[pred1][last+2]=1;
            a[pred2][last+2]=1;
            a[pred3][last+2]=1;
            a[last+1][2]=1;
            a[last+2][2]=1;
            last+=2;
        }
    }

}

int get(int a, int b)
{
    return(a&(1<<b));
}

signed main()
{
    cin>>n;


    while (n!=0)
    {
        vec.pb(n%s);
        n/=s;
    }



    for (int i=0;i<vec.size();i++)
        make_(i,vec[i]);

    cout<<last<<'\n';


    for (int i=1;i<=last;i++)
        for (int j=1;j<=last;j++)
        a[i][j]|=a[j][i];
    //return(0);
    for (int i=1;i<=last;i++)
    {
        for (int j=1;j<=last;j++)
            if (a[i][j])
                cout<<'Y'; else
                cout<<'N';
        cout<<'\n';
    }
}