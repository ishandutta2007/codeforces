#include <iostream>

const int MAX_PEOPLE = 20005;
const int MAX_CHAT = 15;

using namespace std;

bool in_chat [MAX_PEOPLE][MAX_CHAT];
int notifc [MAX_CHAT];
int ans [MAX_PEOPLE];

int main () {
  int peoplec, chatc, eventc;
  cin >> peoplec >> chatc >> eventc;

  for (int i = 1; i <= peoplec; i++) {
    for (int j = 1; j <= chatc; j++) {
      cin >> in_chat[i][j];
    }
  }

  for (int i = 0; i < eventc; i++) {
    int person, chat;
    cin >> person >> chat;

    ans[person]--;
    notifc[chat]++;
  }

  for (int i = 1; i <= peoplec; i++) {
    for (int j = 1; j <= chatc; j++) {
      if (in_chat[i][j]) {
        ans[i] += notifc[j];
      }
    }

    cout << ans[i] << " ";
  }
  cout << endl;
}