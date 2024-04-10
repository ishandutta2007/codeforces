#include <iostream>
#include <string>

using namespace std;

void draw () {
  cout << "once again" << endl;
  exit(0);
}

void lose () {
  cout << "quailty" << endl;
  exit(0);
}

void win () {
  cout << "tokitsukaze" << endl;
  exit(0);
}

const int MAX_N = 1e5 + 5;


bool pref_un [MAX_N];
bool suff_un [MAX_N];

int main () {
  int length, K;
  string str;
  cin >> length >> K;
  cin >> str;

  if (length == K) {
    win();
  }
  
  pref_un[0] = 1;
  for (int i = 1; i < length; i++) {
    pref_un[i] = pref_un[i - 1] && (str[i] == str[i - 1]);
  }

  suff_un[length - 1] = 1;
  for (int i = length - 2; i >= 0; i--) {
    suff_un[i] = suff_un[i + 1] && (str[i] == str[i + 1]);
  }

  if (suff_un[K]) {
    win();
  }

  if (pref_un[length - K - 1]) {
    win();
  }

  for (int i = 1; K + i < length; i++) {
    if (pref_un[i - 1] && suff_un[K + i] && str[0] == str[length - 1]) {
      win();
    }
  }

  if (length - K > K) { // otstesse panemine ei kaota kohe
    draw();
  }
  for (int i = 1; K + i < length; i++) {
    if (!pref_un[i - 1] || !suff_un[K + i]) {
      draw();
    }
  }

  lose();
}