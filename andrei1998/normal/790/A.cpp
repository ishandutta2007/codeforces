#include <iostream>
#include <string>
#include <vector>

using namespace std;

string strs[100];

int main()
{
    int sz = 0;
    for (char let = 'a'; let <= 'z'; ++ let) {
        string str;
        str += let;
        strs[++ sz] = "A" + str;
        strs[++ sz] = "B" + str;
    }

    vector <string> ans;
    int N, K;
    cin >> N >> K;

    for (int i = 1; i < K; ++ i)
        ans.push_back(strs[i]);

    for (int i = K; i <= N; ++ i) {
        string str;
        cin >> str;

        if (str != "NO")
            ans.push_back(strs[i]);
        else
            ans.push_back(ans[i - K]);
    }

    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    return 0;
}