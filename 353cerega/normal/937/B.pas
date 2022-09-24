VAR
  a, b, c, i, j, p, y, p1: LONGINT;
BEGIN
  READLN(p1,y);
  p := p1;
IF p=y
THEN
  WRITELN(-1)
ELSE
BEGIN
  IF p>y DIV p
  THEN
    BEGIN
      p := 0;
      WHILE p*p<y
      DO
        p := p+1;
    END;
  FOR i := y DOWNTO (y-500) DO
    BEGIN
      IF (i<=p1)
      THEN
        BEGIN
          WRITELN(-1);
          BREAK;
        END
      ELSE
        FOR j := 2 TO p DO
          IF i MOD j=0
          THEN
            BREAK
          ELSE
            IF j=p
            THEN
              BEGIN
                WRITELN(i);
                a := 1;
              END;
      IF a=1
      THEN
        BREAK;
    END;
END;
END.