VAR
  a, b, c, d, i, j, l1, l2, n, k, h, Kol: LONGINT;
  Res: INT64;
  M, V, No, S: ARRAY[0..300000] OF LONGINT;
  ngr, vgr, u: DOUBLE;
PROCEDURE QSort(l,r: LONGINT);
VAR
  e, f, q, q1, w: LONGINT;
BEGIN
  e := l;
  f := r;
  q := M[(l+r) DIV 2];
  q1 := V[(l+r) DIV 2];
  WHILE e<=f
  DO
    BEGIN
      WHILE (M[e]<q) OR ((M[e]=q) AND (V[e]<q1)) DO e := e+1;
      WHILE (M[f]>q) OR ((M[f]=q) AND (V[f]>q1)) DO f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := M[e];
          M[e] := M[f];
          M[f] := w;
          w := V[e];
          V[e] := V[f];
          V[f] := w;
          w := No[e];
          No[e] := No[f];
          No[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF e<r THEN QSort(e,r);
  IF l<f THEN QSort(l,f);
END;

BEGIN
  READLN(n,k,h);
  FOR i := 1 TO n DO
    READ(M[i]);
  FOR i := 1 TO n DO
    BEGIN
      READ(V[i]);
      No[i] := i;
    END;
  QSort(1,n);
  ngr := -1;
  vgr := 1000000011;
  FOR j := 1 TO 500 DO
    BEGIN
      u := (vgr+ngr)/2;
      Kol := 0;
      FOR i := 1 TO n DO
        IF (h*(Kol+1)/V[i])<u
        THEN
          BEGIN
            Kol := Kol+1;
            S[Kol] := No[i];
          END;
      IF Kol>=k
      THEN
        vgr := u
      ELSE
        ngr := u;
    END;
  Kol := 0;
  FOR i := 1 TO n DO
    IF (h*(Kol+1)/V[i])<vgr
    THEN
      BEGIN
        Kol := Kol+1;
        S[Kol] := No[i];
      END;
  FOR i := 1 TO k DO
    WRITE(S[i],' ');
END.