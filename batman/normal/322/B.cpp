#include <bits/stdc++.h>
using namespace std;
long long r,g,b,ex,ex2,ans2;
vector <long long> ans;
int main()
{ 
    cin>>r>>g>>b;
    if(!r)
    {
        cout<<g/3+b/3<<endl;
        return 0;
    }
    if(!g)
    {
        cout<<r/3+b/3<<endl;
        return 0;
    }
    if(!b)
    {
        cout<<g/3+r/3<<endl;
        return 0;
    }
    //
    ex=min(r,min(g,b));
    ans2+=ex;
    ex2=(r-ex)/3;
    ans2+=ex2;
    ex2=(g-ex)/3;
    ans2+=ex2;
    ex2=(b-ex)/3;
    ans2+=ex2;
    ans.push_back(ans2);
    ans2=0;
    //
    ex=r%3;
    ans2+=ex;
    ex2=(r-ex)/3;
    ans2+=ex2;
    ex2=(g-ex)/3;
    ans2+=ex2;
    ex2=(b-ex)/3;
    ans2+=ex2;
    ans.push_back(ans2);
    ans2=0;
    //
    ex=g%3;
    ans2+=ex;
    ex2=(r-ex)/3;
    ans2+=ex2;
    ex2=(g-ex)/3;
    ans2+=ex2;
    ex2=(b-ex)/3;
    ans2+=ex2;
    ans.push_back(ans2);
    ans2=0;
    //
    ex=b%3;
    ans2+=ex;
    ex2=(r-ex)/3;
    ans2+=ex2;
    ex2=(g-ex)/3;
    ans2+=ex2;
    ex2=(b-ex)/3;
    ans2+=ex2;
    ans.push_back(ans2);
    ans2=0;
    sort(ans.begin(),ans.end());
    cout<<ans[3];   
    return 0;
}