VAR
  a, b, c, d, i, j, N, M, k, cnt, ind, flag: LONGINT;
  Mas1, Mas2: ARRAY[0..500000] OF LONGINT;
  Massiv: ARRAY[0..2000,0..2000] OF LONGINT;
PROCEDURE QSort1(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  IF (f-e<10000)
  THEN
    q := Mas1[(e+f) DIV 2]
  ELSE
    q := Mas1[((e+f) DIV 2)+3000];
  WHILE e<=f
  DO
    BEGIN
      WHILE Mas1[e]<q
      DO
        e := e+1;
      WHILE Mas1[f]>q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := Mas1[e];
          Mas1[e] := Mas1[f];
          Mas1[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF f>l
  THEN
    QSort1(l,f);
  IF e<r
  THEN
    QSort1(e,r);
END;
PROCEDURE QSort2(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  IF (f-e<10000)
  THEN
    q := Mas2[(e+f) DIV 2]
  ELSE
    q := Mas2[((e+f) DIV 2)+3000];
  WHILE e<=f
  DO
    BEGIN
      WHILE Mas2[e]<q
      DO
        e := e+1;
      WHILE Mas2[f]>q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := Mas2[e];
          Mas2[e] := Mas2[f];
          Mas2[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF f>l
  THEN
    QSort2(l,f);
  IF e<r
  THEN
    QSort2(e,r);
END;
BEGIN
  READ(a,b,k);
  FOR i := 1 TO a DO
    READ(Mas1[i]);
  QSort1(1,a);
  FOR i := 1 TO b DO
    READ(Mas2[i]);
  QSort2(1,b);
  ind := a;
  FOR i := b DOWNTO 0 DO
    BEGIN
      WHILE Mas1[ind]>Mas2[i]
      DO
        BEGIN
          cnt := cnt-1;
          ind := ind-1;
        END;
      IF cnt<0
      THEN
        flag := 1;
      cnt := cnt+1;
    END;
  IF flag=1
  THEN
    WRITELN('YES')
  ELSE
    WRITELN('NO');
END.