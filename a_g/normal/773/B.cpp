#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> solves(5);
  vector<int> vasya(5);
  vector<int> petya(5);
  vector<int> adv;
  for (int j = 0; j < 5; j++) {
    cin >> vasya[j];
    if (vasya[j] != -1) solves[j]++;
  }
  for (int j = 0; j < 5; j++) {
    cin >> petya[j];
    if (petya[j] != -1) solves[j]++;
  }
  for (int j = 0; j < 5; j++) {
    if (petya[j] != -1 && petya[j] < vasya[j]) {
      adv.push_back(j);
    }
  }
  for (int i = 0; i < n-2; i++) {
    for (int j = 0; j < 5; j++) {
      int val;
      cin >> val;
      if (val != -1) solves[j]++;
    }
  }
  for (int i = 0; i < 32*n; i++) {
    int participants = n+i;
    int vscore = 0;
    int pscore = 0;
    for (int j = 0; j < 5; j++) {
      int ratio = 999;
      int weight;
      if (solves[j]) ratio = participants/solves[j];
      if (ratio == 1) weight = 500;
      else if (ratio < 4) weight = 1000;
      else if (ratio < 8) weight = 1500;
      else if (ratio < 16) weight = 2000;
      else if (ratio < 32) weight = 2500;
      else weight = 3000;
      if (vasya[j] != -1) {
        vscore += weight-vasya[j]*(weight/250);
      }
      if (petya[j] != -1) {
        pscore += weight-petya[j]*(weight/250);
      }
    }
    if (vscore > pscore) {
      cout << i << endl;
      return 0;
    }
    for (int j: adv) {
      solves[j]++;
    }
  }
  cout << -1 << endl;
}