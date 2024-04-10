VAR
  a, b, i, j, k, n, m, flag, cnt, cur, ans: LONGINT;
  Mas: ARRAY[0..500000] OF LONGINT;
{PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  q := Mas[(e+f) DIV 2];
  WHILE e<=f
  DO
    BEGIN
      WHILE Mas[e]<q
      DO
        e := e+1;
      WHILE Mas[f]>q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := Mas[e];
END;}
BEGIN
  READLN(n);
  FOR i := 1 TO n DO
    BEGIN
      READ(a);
      IF (Mas[a]=0) AND (a>0)
      THEN
        ans := ans+1;
      Mas[a] := 1;
    END;
    
  WRITELN(ans);
END.