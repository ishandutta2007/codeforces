VAR
  a, b, c, d, i, j, k, n1, n2, flag, cnt, tmp, ans, len, cur1, cur2: LONGINT;
  Sum1, Sum2: INT64;
  Ch: CHAR;
  Mas, M, Inp, M1, x, y: ARRAY[0..1000000] OF LONGINT;
PROCEDURE QSort(l,r: LONGINT);
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
END;

BEGIN
  READLN(n1,n2);
  FOR i := 1 TO n1 DO
    READ(x[i]);
  FOR i := 1 TO n2 DO
    READ(y[i]);
  cur1 := 0;
  cur2 := 0;
  Sum1 := 0;
  Sum2 := 0;
  ans := 0;
  WHILE cur1<n1
  DO
    BEGIN
      cur1 := cur1+1;
      Sum1 := Sum1+x[cur1];
      IF Sum1=Sum2
      THEN
        ans := ans+1;
      WHILE Sum1>Sum2
      DO
        BEGIN
          cur2 := cur2+1;
          Sum2 := Sum2+y[cur2];
          IF Sum1=Sum2
          THEN
            ans := ans+1;
        END;
    END;
  WRITELN(ans);
END.