#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<" "<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}
const long long INF=3e18;


#define int long long

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
if(s[i+1]=='.')continue;
        if(s[i]=='@')
        {
            int pre_val=0;
            int suf_val=0;

            int p=0;
            for(int j=i+1;j<n && s[j]!='@' && s[j]!='_' && p<=1;j++)
            {
                if(s[j]=='.')
                    p++;
                else
                {
                    if(p==1)
                    {if(isdigit(s[j]))
                        break;
                    else if(isalpha(s[j]))suf_val++;}
                }
            }
            for(int j=i-1;j>=0 && s[j]!='@' && s[j]!='.';j--)
            {
                if(isalpha(s[j]))
                    pre_val++;
            }
            ans+=pre_val*suf_val;
        }
    }
    cout<<ans<<endl;
}