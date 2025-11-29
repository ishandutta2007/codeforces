# Codeforces Solutions Archive

This repository is a comprehensive collection of solutions from the competitive programming platform [Codeforces](https://codeforces.com/). It serves as a valuable resource for learning and practicing algorithms and data structures. The solutions are organized by usernames of the Codeforces participants.

This archive is powered by [CPScraper](https://github.com/ishandutta2007/CPScraper), a tool designed to scrape and organize competitive programming solutions.

## Why This Repository?

- **Learn from the best:** Analyze solutions from top-rated competitive programmers.
- **Practice and improve:** Find solutions to problems you're stuck on and learn new techniques.
- **A vast collection:** With thousands of solutions, this is one of the most extensive Codeforces archives available.

## How to Use This Repository

Due to the large size of this repository, it's recommended to perform a sparse checkout to clone only the solutions you need.

### Sparse Checkout Instructions

1. **Clone the repository with sparse checkout enabled:**
   ```bash
   git clone --filter=blob:none --no-checkout --depth 1 --sparse https://github.com/ishandutta2007/codeforces.git
   cd codeforces
   ```

2. **Specify the folders you want to download.** For example, to download solutions from `tourist` and `benq`:
   ```bash
   git sparse-checkout set README.md tourist benq
   ```

3. **Checkout the files:**
   ```bash
   git checkout
   ```

For more information on sparse checkouts, you can refer to the official [Git documentation](https://git-scm.com/docs/git-sparse-checkout).

## Contributing

Contributions are welcome! If you have solutions you'd like to add, please follow the existing directory structure (organizing by Codeforces username).

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
