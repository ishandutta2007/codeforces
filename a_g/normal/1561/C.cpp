#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> values, int n);
void swap(int a[], int n, int i);

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<pair<int, int>> values;
    for (int j = 0; j < n; j++) {
      int size, mp = 0;
      cin >> size;
      for (int l = 0; l < size; l++) {
        int armor;
        cin >> armor;
        mp = max(mp, armor + 1 - l);
      }
      values.push_back(make_pair(size, mp));
    }
    cout << solve(values, n) << endl;
  }
}

bool compare(const pair<int, int>&i, const pair<int, int>&j) 
{ 
  return i.second < j.second; 
} 

int solve(vector<pair<int, int>> values, int n) {
  sort(values.begin(), values.end(), compare);
  int sum = 0;
  int mp = 0;
  for (int i = 0; i < n; i++) {
    mp = max(mp, values[i].second - sum);
    sum += values[i].first;
  }
  return mp;
}