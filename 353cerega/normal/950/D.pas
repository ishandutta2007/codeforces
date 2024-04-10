VAR
  a, b, c, d, i, j, k, flag, cnt, tmp, ans, len, cur1, cur2, q: LONGINT;
  n, x: INT64;
  Ch: CHAR;
  //Mas, M, Inp, M1, x, y: ARRAY[0..1000000] OF LONGINT;
{PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  q := M[(e+f) DIV 2];
  WHILE e<=f
  DO
    BEGIN
      WHILE M[e]<q
      DO
        e := e+1;
      WHILE M[f]>q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := M[e];
          M[e] := M[f];
          M[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF l<f
  THEN
    QSort(l,f);
  IF e<r
  THEN
    QSort(e,r);
END;}

BEGIN
  READLN(n,q);
  FOR i := 1 TO q DO
    BEGIN
      READLN(x);
      x := 2*n-x;
      WHILE x MOD 2=0
      DO
        x := x DIV 2;
      x := x+1;
      x := n-(x DIV 2)+1;
      WRITELN(x);
    END;
END.