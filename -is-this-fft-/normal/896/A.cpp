#include <iostream>
#include <string>

using namespace std;

typedef long long llong;

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string fl = "What are you doing while sending \"";
const string fm = "\"? Are you busy? Will you send \"";
const string fr = "\"?";

const int MAX_N = 100005;
const llong INF = 1e18 + 5;

llong len [MAX_N];

char char_at (int gen, llong pos) {
  if (gen == 0) {
    if (pos < f0.size()) {
      return f0[pos];
    }
    return '.';
  }

  if (pos < fl.size()) {
    return fl[pos];
  }

  if (pos < fl.size() + len[gen - 1]) {
    return char_at(gen - 1, pos - fl.size());
  }

  if (pos < fl.size() + len[gen - 1] + fm.size()) {
    return fm[pos - fl.size() - len[gen - 1]];
  }

  if (pos < fl.size() + len[gen - 1] + fm.size() + len[gen - 1]) {
    return char_at(gen - 1, pos - fl.size() - len[gen - 1] - fm.size());
  }

  if (pos < fl.size() + len[gen - 1] + fm.size() + len[gen - 1] + fr.size()) {
    return fr[pos - fl.size() - len[gen - 1] - fm.size() - len[gen - 1]];
  }

  return '.';
}

int main () {
  len[0] = f0.size();
  for (int i = 1; i < MAX_N; i++) {
    if (len[i - 1] <= INF / 2) {
      len[i] = min(INF, (llong) (fl.size() + fm.size() + fr.size() + 2 * len[i - 1]));
    } else {
      len[i] = INF;
    }
  }

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int gen;
    llong pos;
    cin >> gen >> pos;
    cout << char_at(gen, pos - 1);
  }
  cout << endl;
}