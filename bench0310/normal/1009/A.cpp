#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int games[n];
    queue<int> q;
    for(int i=0;i<n;i++) cin >> games[i];
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int current;
    current=q.front();
    q.pop();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(current<games[i]) continue;
        cnt++;
        if(!q.empty())
        {
            current=q.front();
            q.pop();
        }
        else break;
    }
    cout << cnt << endl;
    return 0;
}