#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector <pair <int, int>> ans;
    for (; (N - 2) % 3 && N; N--)
        ans.push_back({N, N});
    vector <int> other;
    for (int i = 1; i <= N; i++)
        if ((i - 1) % 3)
            other.push_back(i);
    for (int i = 0; i < other.size(); i++)
        ans.push_back({other[i], other[(int)other.size() - i - 1]});
    printf("%d\n", ans.size());
    for (auto it : ans)
        printf("%d %d\n", it.first, it.second);
    return 0;
}