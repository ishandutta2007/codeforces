#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto f=[&](int k)->int{return (n-n/k-((n%k)!=0)-(k-1));};
    int k=1;
    for(int i=1;i<=n;i++) if(f(i)>f(k)) k=i;
    vector<bool> on(n+1,0);
    vector<bool> wish(n+1,0);
    vector<array<int,2>> groups;
    for(int i=1;i<=n-1;i+=k) for(int j=i;j<=min(i+k-2,n-1);j++) wish[j]=1;
    int cnt=0;
    while(cnt<f(k))
    {
        vector<int> now;
        for(int i=1;i<=n;i++) if(!on[i]&&wish[i]) now.push_back(i);
        for(int i=1;i<=n;i++) if(on[i]||!wish[i]) now.push_back(i);
        cout << k << " ";
        for(int i=0;i<k;i++)
        {
            cout << now[i] << " \n"[i==k-1];
            if(!on[now[i]]) cnt++;
            on[now[i]]=1;
        }
        cout.flush();
        int x;
        cin >> x;
        if(x==-1) exit(0);
        for(int i=0;i<k;i++)
        {
            if(on[x]) cnt--;
            on[x]=0;
            x=(x<n?x+1:1);
        }
    }
    cout << "0\n";
    cout.flush();
    return 0;
}