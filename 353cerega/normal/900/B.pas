VAR
  a, b, c, e, i: LONGINT;
  M: ARRAY[1..100] OF LONGINT;
BEGIN
  READLN(a,b,c);
  e := a MOD b;
  FOR i := 1 TO 1000000 DO
    BEGIN
      e := e*10;
      IF (e DIV b)=c
      THEN
        BEGIN
          WRITELN(i);
          BREAK;
        END;
      e := e MOD b;
      IF i=1000000
      THEN
        WRITELN(-1);
    END;
END.