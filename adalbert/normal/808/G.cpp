
#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=500000;

int dp[arr][3];
bool can[arr];

bool equal_(string st1, string st2, int l1, int r1, int l2, int r2)
{
    if (l1<0 || r1>=st1.size() || l2<0 || r2>=st2.size())
    {
        while(1)
        {

        }
    }
    for (int i=l1;i<=r1;i++)
        if (st1[i]!=st2[i+l2-l1] && st1[i]!='?' & st2[i+l2-l1]!='?') return(0);
    return(1);
}
ll pref1[arr],step1[arr];
const ll md1=1e9+7;
const ll base1=39;
ll pref2[arr],step2[arr];
const ll md2=1e9+9;
const ll base2=38;

bool equal_(int l1, int r1, int l2, int r2)
{
    return(((pref2[r1]-pref2[l1-1]+2*md2)%md2*step2[r2-r1])%md2==(pref2[r2]-pref2[l2-1]+md2)%md2 && ((pref1[r1]-pref1[l1-1]+2*md1)%md1*step1[r2-r1])%md1==(pref1[r2]-pref1[l2-1]+md1)%md1);
}
void make_can(string st)
{
    can[0]=1;

    step1[0]=1;
    for (int i=1;i<=st.size();i++)
        step1[i]=(step1[i-1]*base1)%md1;
    for (int i=1;i<=st.size();i++)
        pref1[i]=(pref1[i-1]+(st[i-1]-'a'+1)*step1[i]%md1)%md1;

    step2[0]=1;
    for (int i=1;i<=st.size();i++)
        step2[i]=(step2[i-1]*base2)%md2;
    for (int i=1;i<=st.size();i++)
        pref2[i]=(pref2[i-1]+(st[i-1]-'a'+1)*step2[i]%md2)%md2;

    for (int i=1;i<st.size();i++)
        can[i]=equal_(1,i,st.size()-i+1,st.size());
}

signed main()
{
    string st1,st2;
    cin>>st1>>st2;
    make_can(st2);

    for (int i=st2.size();i<=st1.size();i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);

        for (int j=st2.size()-1;j>=1;j--)
        {
            if (st1[i-st2.size()+j]!=st2[j] && st1[i-st2.size()+j]!='?') break;
            if (can[j])
            {
                if (dp[i-st2.size()+j][1]!=0)
                    dp[i][1]=max(dp[i][1],dp[i-st2.size()+j][1]+1);
            }
        }

        if (equal_(st1,st2,i-st2.size(),i-1,0,st2.size()-1))
            dp[i][1]=max(dp[i][1],max(dp[i-st2.size()][1],dp[i-st2.size()][0])+1);
    }

    cout<<max(dp[st1.size()][1],dp[st1.size()][0])<<'\n';

}
/*
irsdljdahusytoclelxidaaiaiaicaiaiaiaiiaiaiyyexmohdwmeyycaiaiaitclluaiaiaiznxweleaiaiaiixdwehyruhizbc
aiaiai
*/