VAR
  a, b, c, i, j, j1, N, No, t, Kol, flag, time: LONGINT;
  Mas, M, k: ARRAY[0..200000] OF LONGINT;
  Massiv: ARRAY[0..200,0..200] OF LONGINT;
BEGIN
  READLN(N);
  FOR i := 1 TO N DO
    READ(Mas[i]);
  FOR j := 1 TO N DO
    BEGIN
      READ(k[j]);
      FOR i := 1 TO k[j] DO
        READ(Massiv[j,i]);
      READLN;
    END;
  time := 20000000;
  FOR i := 1 TO 3 DO
    BEGIN
      Kol := 0;
      No := i;
      t := 0;
      FOR j := 1 TO N DO
        M[j] := Mas[j];
      WHILE Kol<N
      DO
        BEGIN
          flag := 0;
          FOR j := 1 TO N DO
            IF (M[j]=No)
            THEN
              BEGIN
                a := 0;
                FOR j1 := 1 TO k[j] DO
                  IF M[Massiv[j,j1]]<>-1
                  THEN
                    a := 1;
                IF (a=0)
                THEN
                BEGIN
                flag := 1;
                M[j] := -1;
                Kol := Kol+1;
                END;
              END;
          IF (flag<>1)
          THEN
            BEGIN
              No := (No MOD 3)+1;
              t := t+1;
            END;
        END;
      IF t<time
      THEN
        time := t;
    END;
  time := time+N;
  WRITELN(time);
END.