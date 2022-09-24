VAR
  a, b, l, i, j, k, Mana, Kol, Min, ds, cs, da, ca, Max, cur, tmp, MaxKol, ind, li, w, h, n1: LONGINT;
  M, M1, Mas, X, Y, row, col, row1, col1, flag: ARRAY[0..500000] OF LONGINT;
  Res: INT64;
  n, r, rr, al, eps: DOUBLE;
{PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  q := M[(l+r) DIV 2];
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

PROCEDURE Insert(Value: LONGINT);
VAR
  Index, temp: LONGINT;
BEGIN
  Kol := Kol+1;
  Mas[Kol] := Value;
  Index := Kol;
  WHILE (Index>1) AND (Mas[Index]>Mas[Index DIV 2])
  DO
    BEGIN
      temp := Mas[Index];
      Mas[Index] := Mas[Index DIV 2];
      Mas[Index DIV 2] := temp;
      Index := Index DIV 2;
    END;
END;

PROCEDURE ExtractMin();
VAR
  Index, temp: LONGINT;
BEGIN
  Min := Mas[1];
  Mas[1] := Mas[Kol];
  Kol := Kol-1;
  Index := 1;
  WHILE ((Index*2<=Kol) AND (Mas[Index]>Mas[Index*2])) OR ((Index*2+1<=Kol) AND (Mas[Index]>Mas[Index*2+1]))
  DO
    BEGIN
      IF ((Kol=Index*2) OR (Mas[Index*2]<Mas[Index*2+1]))
      THEN
        BEGIN
          temp := Mas[Index*2];
          Mas[Index*2] := Mas[Index];
          Mas[Index] := temp;
          Index := Index*2;
        END
      ELSE
        BEGIN
          temp := Mas[Index*2+1];
          Mas[Index*2+1] := Mas[Index];
          Mas[Index] := temp;
          Index := Index*2+1;
        END;          
    END;      
END;}

BEGIN
  READLN(n,r,rr);
  eps := 0.000000001;
  al := rr/(r-rr);
  IF r+eps<rr
  THEN
    WRITELN('NO')
  ELSE
    IF (r/2+eps<rr) AND (n<1.5)
    THEN
      WRITELN('YES')
    ELSE
      IF (r/2+eps<rr)
      THEN
        WRITELN('NO')
      ELSE
  IF arcsin(al)*n-eps<pi
  THEN
    WRITELN('YES')
  ELSE
    WRITELN('NO');
  
END.