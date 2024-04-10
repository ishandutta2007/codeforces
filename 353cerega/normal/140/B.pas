VAR
  a1, b1, a2, b2, a3, b3, n, i, j, k, Mana, Kol, Min, Min1, ds, cs, da, ca, Max, cur, tmp, MaxKol, ind, li, w, h, n1, count, a, Sum: LONGINT;
  M, M1, X, Y, row, col, row1, col1, flag, Ans: ARRAY[0..500000] OF LONGINT;
  Mas, Mas1: ARRAY[0..1000,0..1000] OF LONGINT;
  Res: INT64;
PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  IF r-l<5000
  THEN
    q := M[(l+r) DIV 2]
  ELSE
    q := M[(l+r+3000) DIV 2];
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

{PROCEDURE Insert(Value, Value1: LONGINT);
VAR
  Index, temp: LONGINT;
BEGIN
  Kol := Kol+1;
  Mas[Kol] := Value;
  Mas1[Kol] := Value1;
  Index := Kol;
  WHILE (Index>1) AND (Mas[Index]>Mas[Index DIV 2])
  DO
    BEGIN
      temp := Mas[Index];
      Mas[Index] := Mas[Index DIV 2];
      Mas[Index DIV 2] := temp;
      temp := Mas1[Index];
      Mas1[Index] := Mas1[Index DIV 2];
      Mas1[Index DIV 2] := temp;
      Index := Index DIV 2;
    END;
END;

PROCEDURE ExtractMin();
VAR
  Index, temp: LONGINT;
BEGIN
  Min := Mas[1];
  Min1 := Mas1[1];
  Mas[1] := Mas[Kol];
  Mas1[1] := Mas1[Kol];
  Kol := Kol-1;
  Index := 1;
  WHILE ((Index*2<=Kol) AND (Mas[Index]<Mas[Index*2])) OR ((Index*2+1<=Kol) AND (Mas[Index]<Mas[Index*2+1]))
  DO
    BEGIN
      IF ((Kol=Index*2) OR (Mas[Index*2]>Mas[Index*2+1]))
      THEN
        BEGIN
          temp := Mas[Index*2];
          Mas[Index*2] := Mas[Index];
          Mas[Index] := temp;
          temp := Mas1[Index*2];
          Mas1[Index*2] := Mas1[Index];
          Mas1[Index] := temp;
          Index := Index*2;
        END
      ELSE
        BEGIN
          temp := Mas[Index*2+1];
          Mas[Index*2+1] := Mas[Index];
          Mas[Index] := temp;
          temp := Mas1[Index*2+1];
          Mas1[Index*2+1] := Mas1[Index];
          Mas1[Index] := temp;
          Index := Index*2+1;
        END;          
    END;      
END;
}
BEGIN
  READLN(n);
  M1[0] := n+1;
  FOR i := 1 TO n DO
    FOR j := 1 TO n DO
      BEGIN
        READ(Mas[i,j]);
        Mas1[i,Mas[i,j]] := j;
        Mas1[i,0] := n+1;
      END;
  FOR i := 1 TO n DO
    BEGIN
      READ(M[i]);
      M1[M[i]] := i;
    END;
  FOR i := 1 TO n DO
    BEGIN
      IF M1[i]<M1[Min]
      THEN
        BEGIN
          Min1 := Min;
          Min := i;
          FOR j := 1 TO n DO
            IF j<>i
            THEN
              IF Mas1[j,i]<Mas1[j,Ans[j]]
              THEN
                Ans[j] := i;
          IF Mas1[Min,Min1]<Mas1[Min,Ans[Min]]
          THEN
            Ans[Min] := Min1;
        END
      ELSE
      IF M1[i]<M1[Min1]
      THEN
        BEGIN
          Min1 := i;
          IF Mas1[Min,Min1]<Mas1[Min,Ans[Min]]
          THEN
            Ans[Min] := Min1;
        END;
    END;
  FOR i := 1 TO n DO
    WRITE(Ans[i],' ');
END.