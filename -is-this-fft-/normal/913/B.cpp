#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1005;

vector<int> children [MAX_N];
bool intern [MAX_N];

int main () {
  int vertexc;
  cin >> vertexc;

  for (int i = 2; i <= vertexc; i++) {
    int par;
    cin >> par;

    children[par].push_back(i);
    intern[par] = true;
  }

  for (int i = 1; i <= vertexc; i++) {
    if (intern[i]) {
      int leafc = 0;
      for (int child : children[i]) {
        if (!intern[child]) {
          leafc++;
        }
      }

      if (leafc < 3) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}