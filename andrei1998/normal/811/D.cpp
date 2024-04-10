#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <map>

using namespace std;

const int NMAX = 100 + 5;

int N, M;
string str[NMAX];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

pair <int, int> father[NMAX][NMAX];

map <pair <int, int>, char> Map;

pair <int, int> getTrans(pair <int, int> start, pair <int, int> dest) {
    return make_pair(dest.first - start.first, dest.second - start.second);
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++ i) {
        cin >> str[i];
        str[i] = " " + str[i];
    }

    queue <pair <int, int> > q;
    q.push({1, 1});

    while (!q.empty()) {
        pair <int, int> node = q.front();
        q.pop();

        for (int k = 0; k < 4; ++ k) {
            int lin = node.first + dx[k];
            int col = node.second + dy[k];

            if (lin >= 1 && col >= 1 && lin <= N && col <= M && !father[lin][col].first && str[lin][col] != '*') {
                father[lin][col] = node;
                q.push(make_pair(lin, col));
            }
        }
    }

    pair <int, int> node;
    pair <int, int> save;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (str[i][j] == 'F') {
                save = node = make_pair(i, j);
                break;
            }

    vector <pair <int, int> > sol;
    while (node.first != 1 || node.second != 1) {
        sol.push_back(node);
        node = father[node.first][node.second];
    }

    reverse(sol.begin(), sol.end());

    node = {1, 1};
    for (auto it: sol) {
        pair <int, int> tr = getTrans(node, it);

        if (!Map.count(tr)) {
            if (tr.first) {
                cout << "D" << endl;

                pair <int, int> newNode;
                cin >> newNode.first >> newNode.second;

                if (newNode == node) { //Pe dos
                    Map[make_pair(-1, 0)] = 'D';
                    Map[make_pair(1, 0)] = 'U';

                    cout << "U" << endl;
                    int l, c;
                    cin >> l >> c;
                }
                else {
                    Map[make_pair(-1, 0)] = 'U';
                    Map[make_pair(1, 0)] = 'D';
                }
            }
            else {
                cout << "R" << endl;

                pair <int, int> newNode;
                cin >> newNode.first >> newNode.second;

                if (newNode == node) { //Pe dos
                    Map[make_pair(0, -1)] = 'R';
                    Map[make_pair(0, 1)] = 'L';

                    cout << "L" << endl;
                    int l, c;
                    cin >> l >> c;
                }
                else {
                    Map[make_pair(0, -1)] = 'L';
                    Map[make_pair(0, 1)] = 'R';
                }
            }
        }
        else {
            cout << Map[tr] << endl;
            int l, c; //Not useful
            cin >> l >> c;
        }

        node = it;
    }

    return 0;
}