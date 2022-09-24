VAR
  a, b, c, d, i, j, k, n, flag, cnt, tmp, ans, len, Max, Kol, Mnogo, cur: LONGINT;
  Ch: CHAR;
  Mas, M, Inp, M1, kek: ARRAY[0..1000000] OF LONGINT;
PROCEDURE QSort(l,r: LONGINT);
VAR
  q, q1, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  IF f-e<10000
  THEN
    BEGIN
      q := M[(e+f) DIV 2];
      q1 := M1[(e+f) DIV 2];
    END
  ELSE
    BEGIN
      q := M[(e+f+5000) DIV 2];
      q1 := M1[(e+f+5000) DIV 2];
    END;
  WHILE e<=f
  DO
    BEGIN
      WHILE (M[e]<q) OR ((M[e]=q) AND (M1[e]<q1))
      DO
        e := e+1;
      WHILE (M[f]>q) OR ((M[f]=q) AND (M1[f]>q1))
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := M[e];
          M[e] := M[f];
          M[f] := w;
          w := M1[e];
          M1[e] := M1[f];
          M1[f] := w;
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
  Mnogo := 1000000000;
  len := 0;
  Mas[0] := 0;
  WHILE NOT EOLN
  DO
    BEGIN
      len := len+1;
      READ(Ch);
      IF Ch='1'
      THEN
        BEGIN
          Inp[len] := 1;
          M[len] := Mas[len-1];
          M1[len] := len;
          Mas[len] := Mas[len-1]-1;
          IF Mas[len]<0
          THEN
            flag := 1;
        END
      ELSE
        BEGIN
          Inp[len] := 0;
          Mas[len] := Mas[len-1]+1;
          M[len] := Mas[len];
          M1[len] := len;
          IF Mas[len]>Max
          THEN
            Max := Mas[len];
        END;
    END;
  IF Mas[len]<Max
  THEN
    flag := 1;
  IF flag=1
  THEN
    WRITELN(-1)
  ELSE
    BEGIN
      QSort(1,len);
      FOR i := 1 TO len DO
        kek[M[i]] := kek[M[i]]+1;
      Mas[1] := Mnogo+M[1];
      Mas[2] := kek[M[1]];
      Mas[3] := M1[1];
      cur := 3;
      FOR i := 2 TO len DO
        BEGIN
          IF M[i]>M[i-1]
          THEN
            BEGIN
              IF Inp[M1[i-1]]=1
              THEN
                flag := 1;
              cur := cur+1;
              Mas[cur] := Mnogo+M[i];
              cur := cur+1;
              Mas[cur] := kek[M[i]];
            END;
          cur := cur+1;
          Mas[cur] := M1[i];
        END;
      IF Inp[M1[len]]=1
      THEN
        flag := 1;
      IF flag=1
      THEN
        WRITELN(-1)
      ELSE
        BEGIN
          WRITELN(M[len]);
          WRITE(Mas[2],' ');
          FOR i := 3 TO cur DO
            BEGIN
              IF Mas[i]>Mnogo
              THEN
                WRITELN
              ELSE
                WRITE(Mas[i],' ');
            END;
        END;
    END;
END.