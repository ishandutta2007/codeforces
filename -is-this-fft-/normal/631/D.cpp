#include <iostream>
#include <vector>
#include <assert.h>

typedef long long llong;

using namespace std;

const int MAX_BLOCK = 200005;

struct block {
  char letter;
  llong count;

  block () {
    letter = '$';
    count = 0;
  }

  block (char il, llong ic) {
    letter = il;
    count = ic;
  }

  block (string s) {
    count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '-') {
	letter = s[i + 1];
	break;
      }

      count *= 10;
      count += s[i] - '0';
    }
  }
};

block operator+ (block a, block b) {
  return block(a.letter, a.count + b.count);
}

bool operator== (block a, block b) {
  return (a.letter == b.letter) && (a.count == b.count);
}

bool operator!= (block a, block b) {
  return !(a == b);
}

int backtab [MAX_BLOCK];

llong kmp (vector<block> text, vector<block> pattern) {
  llong ans = 0;

  int j = 0;
  backtab[1] = 0;
  
  for (int i = 1; i < pattern.size() - 1; backtab[i] = j) {
    while (j >= 1 && pattern[i] != pattern[j]) {
      j = backtab[j];
    }
    
    i++;
    j++;
  }

  int pptr = 1;
  for (int tptr = 1; tptr < text.size() - 1;) {
    while (pptr >= 1 && text[tptr] != pattern[pptr]) {
      pptr = backtab[pptr];
    }
    
    tptr++;
    pptr++;

    if (pptr == pattern.size() - 1) {
      if ((text[tptr - pptr].letter == pattern[0].letter) &&
	  (text[tptr - pptr].count >= pattern[0].count) &&
	  (text[tptr].letter == pattern[pptr].letter) &&
	  (text[tptr].count >= pattern[pptr].count)) {
	ans++;
      }
      pptr = backtab[pptr];
    }
  }

  return ans;
}

int main () {
  int textl, patl;
  cin >> textl >> patl;

  vector<block> text;
  for (int i = 0; i < textl; i++) {
    string blc;
    cin >> blc;
    
    block blo = block(blc);
    
    if (text.size() == 0 || text.back().letter != blo.letter) {
      text.push_back(blo);
    } else {
      text.back() = text.back() + blo;
    }
  }

  vector<block> pattern;
  for (int i = 0; i < patl; i++) {
    string blc;
    cin >> blc;
    
    block blo = block(blc);
    
    if (pattern.size() == 0 || pattern.back().letter != blo.letter) {
      pattern.push_back(blo);
    } else {
      pattern.back() = pattern.back() + blo;
    }
  }

  assert(!pattern.empty());
  assert(pattern.size() <= patl);

  if (pattern.size() == 1) {
    llong ans = 0;

    for (int i = 0; i < text.size(); i++) {
      if (text[i].letter == pattern[0].letter) {
	ans += max(0LL, text[i].count - pattern[0].count + 1);
      }
    }

    cout << ans << endl;
  } else if (pattern.size() == 2) {
    llong ans = 0;

    for (int i = 0; i < text.size() - 1; i++) {
       if ((text[i].letter == pattern[0].letter) &&
	  (text[i].count >= pattern[0].count) &&
	  (text[i + 1].letter == pattern[1].letter) &&
	  (text[i + 1].count >= pattern[1].count)) {
	 ans++;
       }
    }

    cout << ans << endl;
  } else {
    cout << kmp(text, pattern) << endl;
  }
}