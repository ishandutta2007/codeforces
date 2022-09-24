VAR
  N, i, j, j1, j2: LONGINT;
  a, b, c, d, m, m1: ARRAY [1..110000] OF INT64;
  Sum, Sum1, Sum2, Res, Res1, Res2, S, k1, k, k2, x: INT64;
PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  IF (r-l)>10000
  THEN
    q := m[(l+r-4000) DIV 2]
  ELSE
    q := m[(l+r) DIV 2];
  e := l;
  f := r;
  WHILE e<=f
  DO
    BEGIN
      WHILE q>m[e] DO e := e+1;
      WHILE q<m[f] DO f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := m[e];
          m[e] := m[f];
          m[f] := w;
          w := m1[e];
          m1[e] := m1[f];
          m1[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF l<f THEN QSort(l,f);
  IF e<r THEN QSort(e,r);
END;

BEGIN
  READLN(N,S);
  FOR i := 1 TO N DO
    BEGIN
      READLN(c[i],a[i],b[i]);
      IF (a[i]>b[i])
      THEN
        BEGIN
          m[i] := a[i]-b[i];
          m1[i] := i;
          Sum1 := Sum1 + c[i];
          Res := c[i]*a[i]+Res;
        END
      ELSE
        BEGIN
          m[i] := a[i]-b[i];
          m1[i] := i;
          Sum2 := Sum2 + c[i];
          Res := c[i]*b[i]+Res;
        END;
    END;
  IF ((Sum1+Sum2-1) DIV S)+1=((Sum2-1) DIV S)+((Sum1-1) DIV S)+2
  THEN
    WRITELN(Res)
  ELSE
    BEGIN
      QSort(1,N);
      FOR i := 1 TO N DO
        IF m[i]>=0
        THEN
          BEGIN
            IF (m[i]=0)
            THEN
              j1 := i+1;
            IF (m[i]>0) AND (j2=0)
            THEN
              j2 := i-1;
          END
        ELSE
          j1 := i+1;
      k1 := (Sum1 MOD S);
      k2 := (Sum2 MOD S);
      Res1 := Res;
      WHILE j1<=N
      DO
        BEGIN
          x := m1[j1];
          IF c[x]>=k1
          THEN
            BEGIN
              Res1 := Res1-k1*m[j1];
              j1 := N+1;
              k1 := 0;
            END
          ELSE
            BEGIN
              k1 := k1-c[x];
              Res1 := Res1-c[x]*m[j1];
            END;
          j1 := j1+1;
        END;
      Res2 := Res;
      WHILE j2>0
      DO
        BEGIN
          x := m1[j2];
          IF c[x]>=k2
          THEN
            BEGIN
              Res2 := Res2+k2*m[j2];
              j2 := 0;
              k2 := 0;
            END
          ELSE
            BEGIN
              k2 := k2-c[x];
              Res2 := Res2+c[x]*m[j2];
            END;
          j2 := j2-1;
        END; 
      IF k2<>0
      THEN
        Res2 := 0;
      IF k1<>0
      THEN
        Res1 := 0;
      IF Res1>Res2
      THEN
        WRITELN(Res1)
      ELSE
        WRITELN(Res2);
    END;
END.