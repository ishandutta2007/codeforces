VAR
  a: ARRAY[0..1000] OF LONGINT;
  Stroka: ARRAY[1..500000] OF CHAR;
  Ch: CHAR;
  N, k, ans, i, j, i1, i2, j1: LONGINT;
BEGIN
  READLN(N);
  FOR i := 1 TO N DO
    BEGIN
      READ(Ch);
      a[ORD(Ch)] := a[ORD(Ch)]+1;
    END;
  FOR i := 0 TO 1000 DO
    IF a[i] MOD 2=1
    THEN
      k := k+1;
  FOR j := k TO N DO
    BEGIN
      IF j<>0
      THEN
      IF (N MOD j = 0) AND ((k=0) OR ((N DIV j) MOD 2 = 1))
      THEN
        BEGIN
        ans := j;
        BREAK;
        END;
    END;
  WRITELN(ans);
  i := 0;
  i1 := 0;
  i2 := 1000;
  FOR k := 1 TO ans DO
    BEGIN
      j := 0;
      WHILE (j < (N DIV ans) DIV 2)
      DO
        BEGIN
          IF a[i] DIV 2>0
          THEN
            BEGIN
              j := j+1;
              Stroka[j] := CHR(i);
              a[i] := a[i]-2;
            END
          ELSE
            i := i+1;
        END;
      FOR j1 := 1 TO j DO
        WRITE(Stroka[j1]);
      IF ((N DIV ans)-j*2=1)
      THEN
        BEGIN
          WHILE (i1<1000) AND (a[i1] MOD 2=0)
          DO
            i1 := i1+1;
          WHILE (i2>0) AND (a[i2]=0)
          DO
            i2 := i2-1;
          IF (i1>=1000)
          THEN
            BEGIN
              a[i2] := a[i2]-1;
              WRITE(CHR(i2));
            END
          ELSE
            BEGIN
              a[i1] := a[i1]-1;
              WRITE(CHR(i1));
            END;
        END;
      FOR j1 := j DOWNTO 1 DO
        WRITE(Stroka[j1]);
      WRITE(' ');
    END;
END.