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

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int cur=0;
    v(p(char,int)) que(m);
    cin>>que;

    v(bool) fr_b(n,0);
    v(bool) found(n,0);
    for(int i=0;i<m;i++)
    {
        if(que[i].first=='-' && !found[que[i].second-1])cur++,fr_b[que[i].second-1]=1;
        found[que[i].second-1]=1;
    }
    v(bool) OK(n,1);
    if(cur)
        for(int i=0;i<n;i++)
            if(found[i] && !fr_b[i])
                OK[i]=0;


    for(int i=0;i<m;i++)
    {
        if(que[i].first=='+')
        {
            if(cur || (i && que[i-1].second!=que[i].second))OK[que[i].second-1]=0;
            cur++;
        }
        else
        {
            if(cur>1 || (i!=m-1 && que[i+1].second!=que[i].second))OK[que[i].second-1]=0;
            cur--;
        }
    }

    v(int) ans;
    for(int i=0;i<n;i++)
        if(OK[i])ans.push_back(i+1);
    cout<<ans.size()<<endl<<ans<<endl;
}