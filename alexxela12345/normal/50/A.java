import java.io.*;
import java.util.*;

public class Main {

	void solve(Scanner in, PrintWriter out) {
		int m = in.nextInt();
		int n = in.nextInt();
		out.println(m * n / 2);
	}

	void run() {
		try (
		    Scanner in = new Scanner(System.in);
		    PrintWriter out = new PrintWriter(System.out);) {
			solve(in, out);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}