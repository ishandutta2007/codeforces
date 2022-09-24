VAR
  a, b, c, d, i, j, n, m, h, k, cnt, tmp, ans, len, q, Kol, Time, Min, cur: LONGINT;
  Ch: CHAR;
  M1, M2, Mas, St, Fin, Used, Tout, Tout1, Komp, KompKol, flag: ARRAY[0..1000000] OF LONGINT;
PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  q := M1[(e+f) DIV 2];
  WHILE e<=f
  DO
    BEGIN
      WHILE M1[e]<q
      DO
        e := e+1;
      WHILE M1[f]>q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := M1[e];
          M1[e] := M1[f];
          M1[f] := w;
          w := M2[e];
          M2[e] := M2[f];
          M2[f] := w;
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

PROCEDURE QSortv(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  q := Tout[(e+f) DIV 2];
  WHILE e<=f
  DO
    BEGIN
      WHILE Tout[e]>q
      DO
        e := e+1;
      WHILE Tout[f]<q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := Tout[e];
          Tout[e] := Tout[f];
          Tout[f] := w;
          w := Tout1[e];
          Tout1[e] := Tout1[f];
          Tout1[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF l<f
  THEN
    QSortv(l,f);
  IF e<r
  THEN
    QSortv(e,r);
END;

PROCEDURE DFS1(v: LONGINT);
VAR
  i1: LONGINT;
BEGIN
  Time := Time+1;
  IF Used[v]=0
  THEN
    BEGIN
      Used[v] := 1;
      FOR i1 := St[v] TO Fin[v] DO
        BEGIN
          DFS1(M2[i1]);
          Time := Time+1;
        END;
      Time := Time+1;
      Tout[v] := Time;
      Tout1[v] := v;
    END;
END;

PROCEDURE DFS2(v, start: LONGINT);
VAR
  i1: LONGINT;
BEGIN
  IF Used[v]=0
  THEN
    BEGIN
      Used[v] := 1;
      Komp[v] := start;
      KompKol[start] := KompKol[start]+1;
      FOR i1 := St[v] TO Fin[v] DO
        DFS2(M2[i1],start);
    END;
END;

BEGIN
  READLN(n,m,h);
  FOR i := 1 TO n DO
    READ(Mas[i]);
  Kol := 0;
  FOR i := 1 TO m DO
    BEGIN
      READLN(a,b);
      IF ((Mas[a]+1) MOD h)=Mas[b]
      THEN
        BEGIN
          Kol := Kol+1;
          M1[Kol] := a;
          M2[Kol] := b;
        END;
      IF ((Mas[b]+1) MOD h)=Mas[a]
      THEN
        BEGIN
          Kol := Kol+1;
          M1[Kol] := b;
          M2[Kol] := a;
        END;
    END;
  
  IF Kol=0
  THEN
    BEGIN
      WRITELN(1);
      WRITE(1);
    END
  ELSE
  BEGIN
  QSort(1,Kol);
  FOR i := 1 TO n DO
    BEGIN
      St[i] := 1;
      Fin[i] := 0;
    END;
  St[M1[1]] := 1;
  FOR i := 2 TO Kol DO
    IF M1[i]<>M1[i-1]
    THEN
      BEGIN
        Fin[M1[i-1]] := i-1;
        St[M1[i]] := i;
      END;
  Fin[M1[Kol]] := Kol;
  FOR i := 1 TO n DO
    DFS1(i);
  QSortv(1,n);
  FOR i := 1 TO Kol DO
    BEGIN
      a := M1[i];
      M1[i] := M2[i];
      M2[i] := a;
    END;
  QSort(1,Kol);
  FOR i := 1 TO n DO
    BEGIN
      St[i] := 1;
      Fin[i] := 0;
    END;
  St[M1[1]] := 1;
  FOR i := 2 TO Kol DO
    IF M1[i]<>M1[i-1]
    THEN
      BEGIN
        Fin[M1[i-1]] := i-1;
        St[M1[i]] := i;
      END;
  Fin[M1[Kol]] := Kol;
  FOR i := 1 TO n DO
    Used[i] := 0;
  FOR i := 1 TO n DO
    DFS2(Tout1[i],Tout1[i]);
  FOR i := 1 TO Kol DO
    BEGIN
      a := M1[i];
      M1[i] := M2[i];
      M2[i] := a;
      M1[i] := Komp[M1[i]];
      M2[i] := Komp[M2[i]];
      IF M1[i]<>M2[i]
      THEN
        flag[Komp[M1[i]]] := 1;
    END;
  Min := n+1;
  FOR i := 1 TO n DO
    BEGIN
      IF (KompKol[i]>0) AND (flag[i]=0) AND (KompKol[i]<Min)
      THEN
        BEGIN
          cur := i;
          Min := KompKol[i];
        END;
    END;
  WRITELN(Min);
  FOR i := 1 TO n DO
    IF Komp[i]=cur
    THEN
      WRITE(i,' ');
  END;
END.