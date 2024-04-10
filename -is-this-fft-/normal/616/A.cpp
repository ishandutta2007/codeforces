#include <iostream>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  
  string numa = "";
  bool lead = true;
  char c;
  while (true) {
    cin >> noskipws >> c;
    if (c == '\n') {
      break;
    } else if (c != '0') {
      lead = false;
    }
    
    if (!lead) {
      numa += c;
    }
  }
  if (numa.size() == 0) {
    numa = "0";
  }

  string numb = "";
  lead = true;  
  while (true) {
    cin >> noskipws >> c;
    if (c == '\n') {
      break;
    } else if (c != '0') {
      lead = false;
    }
    
    if (!lead) {
      numb += c;
    }
  }
  if (numb.size() == 0) {
    numb = "0";
  }

  if (numa.size() < numb.size()) {
    cout << "<" << endl;
  } else if (numa.size() > numb.size()) {
    cout << ">" << endl;
  } else {
    bool done = false;
    for (int i = 0; i < numa.size(); i++) {
      if (numa[i] < numb[i]) {
	cout << "<" << endl;
	done = true;
	break;
      } else if (numa[i] > numb[i]) {
	cout << ">" << endl;
	done = true;
	break;
      }
    }

    if (!done) {
      cout << "=" << endl;
    }
  }
}