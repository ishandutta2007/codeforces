VAR
  a, b, c, d, e, i, i1, j, Max, Res, Kol, No, n: LONGINT;
  M, Mas: ARRAY[0..1000000] OF LONGINT;
BEGIN
  READLN(n);
  FOR i := 1 TO n DO
    BEGIN
      READ(M[i]);
      IF M[i]>Max
      THEN
        BEGIN
          Max := M[i];
          j := j+1;
          Mas[j] := i;
        END;
    END;
  Mas[j+1] := n+1;
  FOR i := 1 TO j DO
    BEGIN
      Max := M[Mas[i-1]];
      Kol := -1;
      FOR i1 := Mas[i]+1 TO Mas[i+1]-1 DO
        BEGIN
          IF M[i1]>Max
          THEN
            BEGIN
              Max := M[i1];
              Kol := Kol+1;
            END;
        END;
      IF Kol>Res
      THEN
        BEGIN
          Res := Kol;
          No := Mas[i];
        END;
    END;
  IF No<>0
  THEN
    WRITELN(M[No])
  ELSE
    IF n=j
    THEN
      WRITELN(1)
    ELSE
      BEGIN
        Max := 0;
        FOR i := 1 TO n DO
          IF M[i]=i
          THEN
            Max := M[i]
          ELSE
            BEGIN
              WRITELN(i);
              BREAK;
            END;
      END;
END.