#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <numeric>
#include <algorithm>

struct Student {
  int index;
  int msgs;
};

int readInt() {
  int x;
  std::cin >> x;
  return x;
}

int main() {

  int student_count = readInt();

  std::vector<Student> students;

  for (int i = 0; i < student_count; ++i) {
    students.push_back({i, readInt()});
  }

  std::sort(students.begin() + 1, students.end(), [](Student& f_st, Student& s_st) {return f_st.msgs > s_st.msgs;});

  // for (int i = 0; i < student_count; ++i) {
  //   std::cout << students[i].index << " " << students[i].msgs << "\n";
  // }


  int current_student = 0;
  int current_addr = 1;
  int addressed = 1;

  std::vector<std::pair<int, int>> answers;

  bool success = true;

  while (addressed < student_count) {
    if (students[current_student].msgs == 0) {
      success = false;
      break;
    }

    for (int i = 0; i < students[current_student].msgs && current_addr < student_count; ++i) {
      answers.push_back({current_student, current_addr});
      ++current_addr;
      ++addressed;
    }
    ++current_student;
    if (current_student >= current_addr) {
      success = false;
      break;
    }
  }

  // std::cout << "debug\n";
  // for (int i = 0; i < answers.size(); ++i) {
  //   std::cout << answers[i].first << " " << answers[i].second << "\n";
  // }
  // std::cout << "debug\n";

  if (!success) {
    std::cout << "-1\n";
  } else {
    std::cout << answers.size() << "\n";
    for (std::pair<int, int>& index_pair : answers) {
      std::cout << students[index_pair.first].index + 1 << " " << students[index_pair.second].index + 1 << "\n";
    }
  }

  return 0;
}