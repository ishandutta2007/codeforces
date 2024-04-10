#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;


signed main()
{
    string st1,st2;
    cin>>st1>>st2;
    string stt1="";
    string ans="";
    for (int i=0;i<=1000;i++)
        ans+='z';
    for (int i=0;i<st1.size();i++)
    {
        stt1+=st1[i];
        string stt2="";
            for (int j=0;j<st2.size();j++)
            {
                stt2+=st2[j];
                string now=stt1+stt2;
                ans=min(ans,now);
            }
    }
    cout<<ans;
}