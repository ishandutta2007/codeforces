import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class soldiercards {

	public static void main(String[] args) {
		byte n;

		Scanner in = new Scanner(System.in);
		n = in.nextByte();
		byte k1 = in.nextByte();
		Queue<Byte> p1h = new LinkedList<Byte>();
		
		for (int i=0;i<k1;i++) {
			p1h.add(in.nextByte());
		}
		
		byte k2 = in.nextByte();
		Queue<Byte> p2h = new LinkedList<Byte>();
		for (int i=0;i<k2;i++) {
			p2h.add(in.nextByte());
		}
		in.close();

		SortedSet<String> states = new TreeSet<String>();
		int rounds = 0;
		while (true) {
		if(!states.add(p1h.toString()+p2h.toString())) {
			System.out.println("-1");
			System.exit(0);
		};
		rounds++;
		play (p1h,p2h);
		if (p1h.size() == 0) {
			System.out.println(rounds+" 2");
			System.exit(0);
		}
		if (p2h.size() == 0) {
			System.out.println(rounds+" 1");
			System.exit(0);
		}
		//System.out.println(p1h.toString());
		//System.out.println(p2h.toString());
		}
	}

	private static void play(Queue<Byte> p1h, Queue<Byte> p2h) {
		// TODO Auto-generated method stub
		byte card1 = p1h.poll();
		byte card2 = p2h.poll();
		if (card1 > card2) {
			p1h.add(card2);
			p1h.add(card1);
		} else {
			p2h.add(card1);
			p2h.add(card2);			
		}
	}


};