#include <iostream>

using namespace std;

const string ROCK = "rock";
const string PAPER = "paper";
const string SCISSORS = "scissors";

bool wins (string s, string t) {
  if (s == ROCK && t == SCISSORS) return true;
  if (s == SCISSORS && t == PAPER) return true;
  if (s == PAPER && t == ROCK) return true;
  return false;
}

int main () {
  string F, M, S;
  cin >> F >> M >> S;

  if (wins(F, M) && wins(F, S)) {
    cout << "F" << endl;
  } else if (wins(M, F) && wins(M, S)) {
    cout << "M" << endl;
  } else if (wins(S, F) && wins(S, M)) {
    cout << "S" << endl;
  } else {
    cout << "?" << endl;
  }
}