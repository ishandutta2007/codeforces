#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
using namespace std;
vector <ll> tt[1000];
string s,s1,s2;
char c1,c2,c3,c4;
ll n,m,j,i,k,sc,a[10000],b[10000];
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> c1 >> c2 >> c3 >> c3 >> c4;
    s1=c1;
    s1=s1+c2;
    s2=c4;
    s2+=c3;
    //cout << s1 << "-" << s2 << endl;
    while(1)
    {
       // cout << s1 << " " << s2 << endl;
        if(s1==s2)
        {
            cout << i << endl;
            return 0;
        }
        ll x=s2[0];
        x-=48;
        //cout << s2[1] << endl;
        x++;
        //cout << x << endl;
        if(x==10)
        {
          s2[0]='0';
          x=s2[1];
          x-=48;
          x++;
          char cc=x+48;
          s2[1]=cc;
          if(x==6)
          {
              s2[1]='0';
              x=s1[1]-48;
              x++;
              char cc=x+48;
              s1[1]=cc;
              x=s1[0]-48;
              x*=10;
              x+=s1[1];
              x-=48;
              //cout << x << endl;
              //x=s1[1])*10+s2;
              s1[0]=(x/10)+48;
              s1[1]=(x%10)+48;
              if(x==24)s1="00";
          }
        }else
        {
            char cc;
            cc=x+48;
            s2[0]=cc;
        }
        i++;
    }

    return 0;
}