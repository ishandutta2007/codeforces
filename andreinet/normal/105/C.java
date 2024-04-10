import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.HashMap;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private Map<String, String> repr;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            repr = new HashMap<>();
            repr.put("weapon", "gladiator");
            repr.put("armor", "sentry");
            repr.put("orb", "physician");

            List<Item> weapons = new ArrayList<>();
            List<Item> armors = new ArrayList<>();
            List<Item> orbs = new ArrayList<>();

            Map<String, List<Resident>> have = new HashMap<>();

            int n = in.nextInt();
            while (n-- > 0) {
                String name = in.next();
                String type = in.next();
                int atk = in.nextInt();
                int def = in.nextInt();
                int res = in.nextInt();
                int size = in.nextInt();

                Item current = new Item(name, type, atk, def, res, size);
                switch (type) {
                    case "weapon":
                        weapons.add(current);
                        break;
                    case "armor":
                        armors.add(current);
                        break;
                    case "orb":
                        orbs.add(current);
                        break;
                    default:
                        throw new RuntimeException();
                }
            }

            List<Resident> gladiators = new ArrayList<>();
            List<Resident> sentries = new ArrayList<>();
            List<Resident> physicians = new ArrayList<>();

            n = in.nextInt();
            while (n-- > 0) {
                String name = in.next();
                String type = in.next();
                int bonus = in.nextInt();
                String home = in.next();

                Resident current = new Resident(name, type, bonus);
                if (!have.containsKey(home)) have.put(home, new ArrayList<>());
                have.get(home).add(current);

                switch (type) {
                    case "gladiator":
                        gladiators.add(current);
                        break;
                    case "sentry":
                        sentries.add(current);
                        break;
                    case "physician":
                        physicians.add(current);
                        break;
                }
            }

            boolean canSwitch = false;
            for (Item current : all(weapons, armors, orbs)) {
                int p = have.containsKey(current.name) ?
                        have.get(current.name).size() : 0;
                if (p < current.size) canSwitch = true;
            }

            Collections.sort(gladiators);
            Collections.sort(sentries);
            Collections.sort(physicians);

            Pair<Item, List<Resident>> bestWeapon =
                    selectBest(weapons, gladiators, have, canSwitch);
            Pair<Item, List<Resident>> bestArmor =
                    selectBest(armors, sentries, have, canSwitch);
            Pair<Item, List<Resident>> bestOrb =
                    selectBest(orbs, physicians, have, canSwitch);

            for (Resident e : all(bestWeapon.second, bestArmor.second,
                    bestOrb.second)) {
                e.used = true;
            }

            List<Resident> allResidents = all(gladiators, sentries, physicians);
            for (int i = 0; i < allResidents.size() &&
                    bestWeapon.second.size() < bestWeapon.first.size; ++i) {
                if (!allResidents.get(i).used) {
                    bestWeapon.second.add(allResidents.get(i));
                    allResidents.get(i).used = true;
                }
            }
            for (int i = 0; i < allResidents.size() &&
                    bestArmor.second.size() < bestArmor.first.size; ++i) {
                if (!allResidents.get(i).used) {
                    bestArmor.second.add(allResidents.get(i));
                    allResidents.get(i).used = true;
                }
            }
            for (int i = 0; i < allResidents.size() &&
                    bestOrb.second.size() < bestOrb.first.size; ++i) {
                if (!allResidents.get(i).used) {
                    bestOrb.second.add(allResidents.get(i));
                    allResidents.get(i).used = true;
                }
            }

            write(out, bestWeapon);
            write(out, bestArmor);
            write(out, bestOrb);
        }

        private void write(PrintWriter out, Pair<Item, List<Resident>> obj) {
            out.print(obj.first.name + " " + obj.second.size() + " ");
            for (Resident e : obj.second) {
                out.print(e.name + " ");
            }
            out.println();
        }

        private Pair<Item, List<Resident>> selectBest(List<Item> items,
                                                      List<Resident> residents,
                                                      Map<String, List<Resident>> have,
                                                      boolean canSwitch) {
            if (!canSwitch) {
                String type = items.get(0).type;
                String resType = repr.get(type);
                Item best = null;
                int ans = -1;
                for (Item e : items) {
                    int sum = 0;
                    switch (type) {
                        case "weapon":
                            sum = e.atk;
                            break;
                        case "armor":
                            sum = e.def;
                            break;
                        case "orb":
                            sum = e.res;
                            break;
                    }
                    if (have.containsKey(e.name)) {
                        for (Resident p : have.get(e.name)) {
                            if (resType.equals(p.type)) {
                                sum += p.bonus;
                            }
                        }
                    }
                    if (sum > ans) {
                        best = e;
                        ans = sum;
                    }
                }
                List<Resident> ret = have.containsKey(best.name) ?
                        have.get(best.name) : new ArrayList<>();
                return Pair.make_pair(best, ret);
            } else {
                Collections.sort(residents);
                int n = residents.size();
                int[] sum = new int[n];
                if (n > 0) {
                    sum[n - 1] = residents.get(n - 1).bonus;
                }
                for (int i = n - 2; i >= 0; --i) {
                    sum[i] = sum[i + 1] + residents.get(i).bonus;
                }

                Item best = null;
                int ans = -1;
                for (Item e : items) {
                    int s = 0;
                    switch (e.type) {
                        case "weapon":
                            s = e.atk;
                            break;
                        case "armor":
                            s = e.def;
                            break;
                        case "orb":
                            s = e.res;
                            break;
                    }

                    if (n > 0) {
                        int pos = Math.max(0, n - e.size);
                        s += sum[pos];
                    }

                    if (s > ans) {
                        ans = s;
                        best = e;
                    }
                }

                List<Resident> ret = new ArrayList<>();
                for (int i = Math.max(0, n - best.size); i < n; ++i)
                    ret.add(residents.get(i));
                return Pair.make_pair(best, ret);
            }
        }

        private <T> List<T> all(Collection<T>... A) {
            List<T> result = new ArrayList<>();
            for (Collection<T> e : A) {
                result.addAll(e);
            }
            return result;
        }

        private class Item {
            String name;
            String type;
            int atk;
            int def;
            int res;
            int size;

            Item(String name, String type, int atk, int def, int res, int size) {
                this.name = name;
                this.type = type;
                this.atk = atk;
                this.def = def;
                this.res = res;
                this.size = size;
            }

        }

        private class Resident implements Comparable<Resident> {
            String name;
            String type;
            int bonus;
            boolean used;

            Resident(String name, String type, int bonus) {
                this.name = name;
                this.type = type;
                this.bonus = bonus;
                used = false;
            }


            public int compareTo(Resident o) {
                return Integer.compare(bonus, o.bonus);
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Pair<T, V> implements Comparable<Pair<T, V>> {
        public T first;
        public V second;

        public static <T, V> Pair<T, V> make_pair(T first, V second) {
            return new Pair(first, second);
        }

        public Pair() {
        }

        private Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair<T, V> other) {
            int comp = ((Comparable<T>) first).compareTo(other.first);
            if (comp != 0) return comp;
            return ((Comparable<V>) second).compareTo(other.second);
        }

        public boolean equals(Object other) {
            if (this == other) return true;
            if (other == null || getClass() != other.getClass()) return false;

            Pair pair = (Pair) other;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        public int hashCode() {
            int h1 = first == null ? 0 : first.hashCode();
            int h2 = second == null ? 0 : second.hashCode();
            return 31 * h1 + h2;
        }

    }
}