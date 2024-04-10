VAR
  a, b, c, d, i, j, k, n, flag, cnt, tmp, ans, len: LONGINT;
  Ch: CHAR;
  Mas, M, Inp, M1: ARRAY[0..1000000] OF LONGINT;
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
  READ(a,b,c);
  IF a<b
  THEN
    BEGIN
      d := a;
      a := b;
      b := d;
    END;
  d := a-b;
  IF c<a-b
  THEN
    WRITELN(2*c+2*b)
  ELSE
    BEGIN
      c := c-a+b;
      c := c DIV 2;
      WRITELN(2*a+2*c);
    END;
  
END.