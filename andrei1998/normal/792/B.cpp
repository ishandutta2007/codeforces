#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector <int> v;

int main()
{
    cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; ++ i)
        v[i] = i + 1;

    vector <int> ans;

    int start = 0;
    for (int i = 0; i < K; ++ i) {
        int p;
        cin >> p;

        start = (start + p) % N;
        ans.push_back(v[start]);
        v.erase(v.begin() + start);
        N --;
        if (start == N)
            start = 0;
    }

    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    return 0;
}