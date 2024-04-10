#include"bits/stdc++.h"
using namespace std;
vector<int>v;
void check(int a,int b,int c,int d)
{
    set<pair<int,int> >st;
    int ans1,ans2,ans3,ans4;
    cout<<"?"<<" "<<a<<" "<<b<<" "<<c<<endl;
    cin>>ans4;
    st.insert(make_pair(ans4,7));
    cout<<"? "<<a<<" "<<b<<" "<<d<<endl;
    cin>>ans3;
    st.insert(make_pair(ans3,11));
    cout<<"? "<<a<<" "<<d<<" "<<c<<endl;
    cin>>ans2;
    st.insert(make_pair(ans2,13));
    cout<<"? "<<d<<" "<<b<<" "<<c<<endl;
    cin>>ans1;
    st.insert(make_pair(ans1,14));
    auto it=st.begin();
    int ans=it->second;
    it++;
    ans&=it->second;
    v.clear();
    ans^=15;
    if(ans&(1<<0))v.push_back(a);
    if(ans&(1<<1))v.push_back(b);
    if(ans&(1<<2))v.push_back(c);
    if(ans&(1<<3))v.push_back(d);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        check(1,2,3,4);
        int now=5;
        if(n&1)
        {
            int k=1;
            while(k==v[0]||k==v[1])k++;
            check(v[0],v[1],k,5);
            now++;
        }
        for(;now<=n;now+=2)
        {
            check(v[0],v[1],now,now+1);
        }
        cout<<"! "<<v[0]<<" "<<v[1]<<endl;
    }
    return 0;
}