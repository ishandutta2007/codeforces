#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &it: a)
        cin >> it;
    for(auto &it: b)
        cin >> it;
    int i = find(a.begin(), a.end(), 0) - a.begin();
    while(i > 0)
    {
        swap(a[i], a[i - 1]);
        i--;
    }
    i = find(b.begin(), b.end(), 0) - b.begin();
    while(i > 0)
    {
        swap(b[i], b[i - 1]);
        i--;
    }
    deque<int> A(a.begin() + 1, a.end());
    deque<int> B(b.begin() + 1, b.end());
    while(A[0] != 1)
    {
        A.push_back(A.front());
        A.pop_front();
    }
    while(B[0] != 1)
    {
        B.push_back(B.front());
        B.pop_front();
    }
    if(A == B)
        cout << "YES\n";
    else
        cout << "NO\n";
}