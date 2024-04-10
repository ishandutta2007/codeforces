#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    int used[n];
    memset(used, 0, sizeof(used));
    vector<int> daddy;
    for(int i = 0; i < n; i++)
    {
        int j = i;
        set<int> cur;
        while(!used[j])
        {
            cur.insert(j);
            used[j] = 1;
            j = p[j];
        }
        if(cur.count(p[j]))
            daddy.push_back(p[j]);
    }
    int v = daddy[0];
    for(auto it: daddy)
        if(p[it] == it)
            v = it;
    cout << daddy.size() - (p[v] == v) << "\n";
    for(int i = 0; i < daddy.size(); i++)
        p[daddy[i]] = v;
    for(auto it: p)
        cout << it + 1 << " ";
	return 0;
}