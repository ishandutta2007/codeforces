#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>


using namespace std;

int readInt() {
  int x;
  std::cin >> x;
  return x;
}

std::string readString() {
  std::string s;
  std::cin >> s;
  return s;
}

std::string gen(int i) {
  std::string s= "";
  s += ('A' + i/10);
  s += ('a' + i%10);
  return s;
}

void printVector(const std::vector<int>& v) {
  for (int i : v) {
    std::cout << gen(i) << " ";
  }
  std::cout << "\n";
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n = readInt();
  int k = readInt();

  std::vector<int> nums;



  for (int i = 0; i < k - 1; ++i) {
    nums.push_back(i + 1);
  }

  int maxnum = k - 1;

  for (int i = 0; i < n - k + 1; ++i) {
    std::string ans = readString();
    if (ans == "NO") {
      nums.push_back(nums[(int)nums.size() - (k - 1)]);
    } else {
      ++maxnum;
      nums.push_back(maxnum);
    }
  }

  printVector(nums);


  return 0;
}