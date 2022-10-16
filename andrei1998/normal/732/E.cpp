#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector <pair <int, int> > computers;

priority_queue <pair <int, pair <int, int> > > _queue;

const int NMAX = 200000;
int plugs[NMAX];
int which_socket[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    computers.resize(n);
    for (int i = 0; i < n; ++ i) {
        cin >> computers[i].first;
        computers[i].second = i;
    }

    sort(computers.begin(), computers.end(), greater <pair <int, int> >());

    int c = 0, u = 0;

    for (int i = 0; i < n; ++ i)
        which_socket[i] = -1;

    for (int i = 0; i < m; ++ i) {
        int s = 0;
        cin >> s;

        _queue.push(make_pair(s, make_pair(0, i)));
    }

    for (int i = 0; i < n && !_queue.empty(); ++ i) {
        while (!_queue.empty() && _queue.top().first > computers[i].first) {
            pair <int, pair <int, int> > x = _queue.top();
            _queue.pop();
            _queue.push(make_pair((x.first + 1) / 2, make_pair(x.second.first - 1, x.second.second)));
        }

        if (_queue.empty())
            break;

        if (_queue.top().first == computers[i].first) {
            ++ c;
            u += (-_queue.top().second.first);

            plugs[_queue.top().second.second] = -_queue.top().second.first;
            which_socket[computers[i].second] = _queue.top().second.second;

            _queue.pop();
        }
    }

    cout << c << ' ' << u << '\n';
    for (int i = 0; i < m; ++ i)
        cout << plugs[i] << " \n"[i + 1 == m];
    for (int i = 0; i < n; ++ i)
        cout << which_socket[i] + 1 << " \n"[i + 1 == n];
    return 0;
}