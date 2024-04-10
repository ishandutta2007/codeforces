#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 4005;

typedef long long ll;

ll doc_vol [MAX_N];
ll hall_vol [MAX_N];
ll conf [MAX_N];
bool del [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> doc_vol[i] >> hall_vol[i] >> conf[i];
  }

  vector<int> ans;
  for (int i = 1; i <= length; i++) {
    if (!del[i]) {
      ans.push_back(i);
      ll rem = doc_vol[i];
      ll crem = 0;
      for (int j = i + 1; j <= length; j++) {
        if (!del[j]) {
          conf[j] -= (rem + crem);
          if (conf[j] < 0) {
            del[j] = 1;
            crem += hall_vol[j];
          }
          
          if (rem > 0) rem--;
        }
      }
    }
  }

  cout << (int) ans.size() << endl;
  for (int u : ans){
    cout << u << " ";
  }cout << endl;
}