#include <iostream>
#include <string>

#define A 33

using namespace std;

string s,ans;
int n,a[A];

bool check(int m){
    int ans=0;
    for (int i=0; i<A; ++i)
    ans=ans+(a[i]+m-1)/m;
    return ans<=n;
}

int main()
{
    cin>>s>>n;
    
    int len=s.length();
    
    for (int i=0; i<len; ++i)
    a[s[i]-'a']++;
    
    for (int i=1; i<=len; ++i)
    if (check(i)){
        int ans=0;
        cout<<i<<"\n";
        for (int j=0; j<A; ++j)
        while (a[j]>0){
            a[j]-=i;
            char ch='a'+j;
            cout<<ch;
            ans++;
        }
        while (ans<n)
        cout<<"a",ans++;
        cout<<"\n";
        return 0;
    }
    cout<<"-1\n";
    return 0;
}