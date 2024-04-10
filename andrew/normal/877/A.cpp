#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
string s,s1[100];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    s1[1]="Danil";
    s1[2]="Olya";
    s1[3]="Slava";
    s1[4]="Ann";
    s1[5]="Nikita";
    for(i=1;i<6;i++)
    {
        int kek=s.find(s1[i]);
        if(kek!=-1)ans++;
    }
    if(ans==1)
    {
        ans=0;
        for(i=1;i<6;i++)
        {
            int kek=s.find(s1[i]);
            while(kek!=-1)
            {
                    ans++;
                    for(j=kek;j<=kek+s1[i].size()-1;j++)s[j]='+';
                    kek=s.find(s1[i]);
            }
            if(ans>0)break;
        }
    }
    if(ans==1)vout("YES");
    vout("NO");
return 0;
}