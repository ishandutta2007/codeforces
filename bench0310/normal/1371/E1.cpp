#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> res;
    for(int i=1;i<=2000;i++)
    {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int c:a) q.push(c);
        int x=i;
        int now=0;
        bool ok=1;
        while(!q.empty()||now>0)
        {
            while(!q.empty()&&x>=q.top())
            {
                now++;
                q.pop();
            }
            if((now%p)==0)
            {
                ok=0;
                break;
            }
            x++;
            now--;
        }
        if(ok==1) res.push_back(i);
    }
    cout << res.size() << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    return 0;
}