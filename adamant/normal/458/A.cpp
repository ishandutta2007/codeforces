#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

 main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    reverse(begin(a),end(a));
    reverse(begin(b),end(b));

    for(int i=0;i<a.size();i++) a[i]-='0';
    for(int i=0;i<b.size();i++) b[i]-='0';
    while(a.size() && a[a.size()-1]==0) a.pop_back();
    while(b.size() && b[b.size()-1]==0) b.pop_back();
    a.push_back(0);
    b.push_back(0);
    for(int i=a.size()-1;i>=2;i--) if(a[i]==0 && a[i-1]==1 && a[i-2]==1) a[i]=1,a[i-1]=0,a[i-2]=0,i+=3;
    for(int i=b.size()-1;i>=2;i--) if(b[i]==0 && b[i-1]==1 && b[i-2]==1) b[i]=1,b[i-1]=0,b[i-2]=0,i+=3;
    while(a.size()<b.size()) a.push_back(0);
    while(b.size()<a.size()) b.push_back(0);
    reverse(begin(a),end(a));
    reverse(begin(b),end(b));
    //for(int i=0;i<a.size();i++) cout<<(char)(a[i]+'0');cout<<endl;
    //for(int i=0;i<b.size();i++) cout<<(char)(b[i]+'0');cout<<endl;
    if(a<b) cout<<"<\n";
    if(a>b) cout<<">\n";
    if(a==b) cout<<"=\n";

 }