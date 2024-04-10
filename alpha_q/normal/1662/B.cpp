#include <bits/stdc++.h>

using namespace std;

const int A = 26;

string s[3];
vector <bool> taken[3];
vector <int> pos[A][3];

int main() {
  cin >> s[0] >> s[1] >> s[2];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < s[i].size(); ++j) {
      pos[s[i][j] - 'A'][i].emplace_back(j);
    }
    taken[i].resize(s[i].size());
  }
  vector <tuple <int, int, int, int, int>> matching;
  for (int c = 0; c < A; ++c) {
    priority_queue <pair <int, int>> pq;
    for (int i = 0; i < 3; ++i) pq.emplace(pos[c][i].size(), i);
    while (!pq.empty()) {
      auto [sizeA, idA] = pq.top(); pq.pop();
      auto [sizeB, idB] = pq.top(); pq.pop();
      if (!sizeB) break;
      int posA = pos[c][idA].back(), posB = pos[c][idB].back();
      pos[c][idA].pop_back(), pos[c][idB].pop_back();
      matching.emplace_back(idA, posA, idB, posB, c);
      pq.emplace(sizeA - 1, idA), pq.emplace(sizeB - 1, idB);
    }
  }
  matching.resize(min({s[0].size(), s[1].size(), s[2].size(), matching.size()}));
  for (auto [idA, posA, idB, posB, c] : matching) taken[idA][posA] = taken[idB][posB] = 1;
  for (int i = 0; i < 3; ++i) {
    string rem = "";
    for (int j = 0; j < s[i].size(); ++j) if (!taken[i][j]) rem += s[i][j];
    s[i] = rem;
  }
  vector <string> ans;
  for (auto [idA, posA, idB, posB, c] : matching) {
    int idC = idA ^ 3 ^ idB;
    string cur = string(1, (char) ('A' + c)) + string(1, s[idC].back());
    s[idC].pop_back(), ans.emplace_back(cur);
  }
  priority_queue <pair <int, int>> pq;
  for (int i = 0; i < 3; ++i) pq.emplace(s[i].size(), i);
  while (!pq.empty()) {
    auto [sizeA, idA] = pq.top(); pq.pop();
    auto [sizeB, idB] = pq.top(); pq.pop();
    if (!sizeA) break;
    char one = s[idA].back(), two = 'A'; s[idA].pop_back();
    if (sizeB) two = s[idB].back(), s[idB].pop_back();
    string cur = string(1, one) + string(1, two);
    ans.emplace_back(cur);
    pq.emplace(sizeA - 1, idA), pq.emplace(max(0, sizeB - 1), idB);
  }
  cout << ans.size() << '\n';
  for (string it : ans) cout << it << '\n'; 
  return 0;
}