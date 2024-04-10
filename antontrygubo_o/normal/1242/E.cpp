#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }

    if (n==1)
    {
        cout<<a[0].first<<endl;
        for (int i = 1; i<=a[0].first; i++) cout<<i<<' ';
        return 0;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    a.push_back(mp(2, 0));

    vector<vector<int>> face(n);
    vector<int> current;
    int cur = 1;

    int center = 1;
    face[0].push_back(1);
    for (int i = 2; i<=a[0].first; i++)
    {
        cur++;
        face[0].push_back(i);
        current.push_back(i);
    }

    for (int i = 1; i<n; i++)
    {
        int sz1 = current.size();
        int sz2 = a[i].first;

        if (sz1==2)
        {
            face[i].push_back(center);
            face[i].push_back(current[1]);
            cur++;
            face[i].push_back(cur);
            current.push_back(cur);
            continue;
        }
        int need = max(sz1-sz2+2, a[i+1].first);
        need = min(need, sz1+sz2-4);
        if (need%2 != (sz1+sz2)%2)
            need++;
        int common = (sz1+sz2+2-need)/2;
        for (int j = 0; j<common; j++)
        {
            face[i].push_back(current.back());
            current.pop_back();
        }
        current.push_back((face[i].back()));
        for (int j = 0; j<sz2-common; j++)
        {
            cur++;
            face[i].push_back(cur);
            current.push_back(cur);
        }
        current.push_back(face[i][0]);
    }
    cout<<cur<<endl;
    vector<vector<int>> kek(n);
    for (int i = 0; i<n; i++) kek[a[i].second] = face[i];
    for (int i = 0; i<n; i++)
    {
        for (auto it: kek[i]) cout<<it<<' ';
        cout<<endl;
    }
}