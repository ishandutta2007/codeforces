VAR
  a1, b1, a2, b2, a3, b3, n, i, j, k, Mana, Kol, Min, Min1, ds, cs, da, ca, Max, cur, tmp, MaxKol, ind, li, w, h, n1, count, a: LONGINT;
  M, M1, Mas, Mas1, X, Y, row, col, row1, col1, flag, ans1, ans2, ans3: ARRAY[0..500000] OF LONGINT;
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

PROCEDURE Insert(Value, Value1: LONGINT);
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

BEGIN
  READLN(n);
  FOR i := 1 TO n DO
    READ(M[i]);
  QSort(1,n);
  FOR i := 1 TO n DO
    BEGIN
      IF i=1
      THEN
        count := count+1
      ELSE
        IF M[i]<>M[i-1]
        THEN
          BEGIN
            Insert(count,M[i-1]);
            count := 1;
          END
        ELSE
          count := count+1;
    END;
  Insert(count,M[n]);
  count := 0;
  WHILE Kol>2
  DO
    BEGIN
      count := count+1;
      ExtractMin();
      Ans1[count] := Min1;
      a1 := Min-1;
      b1 := Min1;
      ExtractMin();
      Ans2[count] := Min1;
      a2 := Min-1;
      b2 := Min1;
      ExtractMin();
      Ans3[count] := Min1;
      a3 := Min-1;
      b3 := Min1;
      IF a1<>0
      THEN
        Insert(a1,b1);
      IF a2<>0
      THEN
        Insert(a2,b2);
      IF a3<>0
      THEN
        Insert(a3,b3);
    END;
  WRITELN(count);
  a := 0;
  FOR i := 1 TO count DO
    BEGIN
      WHILE a<3
      DO
        BEGIN
          IF (Ans1[i]>Ans2[i]) AND (Ans1[i]>Ans3[i])
          THEN
            BEGIN
              WRITE(Ans1[i]);
              Ans1[i] := 0;
              a := a+1;
              IF a<3
              THEN
                WRITE(' ');
            END
          ELSE
            IF (Ans2[i]>Ans1[i]) AND (Ans2[i]>Ans3[i])
            THEN
              BEGIN
                WRITE(Ans2[i]);
                Ans2[i] := 0;
                a := a+1;
                IF a<3
                THEN
                  WRITE(' ');
              END
            ELSE
              BEGIN
                WRITE(Ans3[i]);
                Ans3[i] := 0;
                a := a+1;
                IF a<3
                THEN
                  WRITE(' ');
              END;
        END;
      WRITELN;
      a := 0;
    END;
END.