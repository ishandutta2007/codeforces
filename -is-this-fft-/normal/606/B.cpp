#include <iostream>
#include <string>

const int MAX_W = 505;
const int MAX_C = 100005;

using namespace std;

bool vis [MAX_W][MAX_W];
int xpos, ypos;
int height, width;

int main () {
  cin >> height >> width >> xpos >> ypos;
  
  int visc = 0;
  cout << 1 << " ";
  vis[xpos][ypos] = true;
  visc++;

  string dirs;
  cin >> dirs;
  for (int i = 0; i < dirs.size(); i++) {
    char dir = dirs.at(i);
    if (dir == 'U') {
      if (xpos != 1) {
	xpos--;
      }
    } else if (dir == 'L') {
      if (ypos != 1) {
	ypos--;
      }
    } else if (dir == 'D') {
      if (xpos != height) {
	xpos++;
      }
    } else if (dir == 'R') {
      if (ypos != width) {
	ypos++;
      }
    }

    visc += !vis[xpos][ypos];
    if (i == dirs.size() - 1) cout << height * width - visc + !vis[xpos][ypos] << endl;
    else cout << !vis[xpos][ypos] << " ";
    vis[xpos][ypos] = true;
  }
}