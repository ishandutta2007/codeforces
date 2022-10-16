#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

string str;

priority_queue <pair <int, pair <int, int> > > pq;

int main()
{
    int n, a, b, k;

    cin >> n >> a >> b >> k;
    cin >> str;

    str = " " + str;

    int j;

    int cate_pune = 0;
    for (int i = 1; i <= n; i = j + 1) {
        j = i;
        if (str[i] == '0') {
            while (j + 1 <= n && str[j + 1] == '0')
                ++ j;

            if (j - i + 1 >= b) {
                cate_pune += (j - i + 1) / b;
                pq.push({-(j - i + 1) / b, {i, j}});
            }
        }
    }

    vector <int> ans;
    while (cate_pune >= a) {
        int cnt = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();


        ans.push_back(x + b - 1);
        if ((y - x + 1) < 2 * b)
            cate_pune --;
        else {
            cate_pune --;
            pq.push({-(cnt - 1), {x + b, y}});
        }
    }


    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    return 0;
}