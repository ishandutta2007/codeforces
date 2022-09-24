VAR
  c, d, i, j, N, M: LONGINT;
  Ch : CHAR;
  a, b: ARRAY[1..10000] OF CHAR;
  Mas: ARRAY[0..500000] OF LONGINT;
  Massiv: ARRAY[0..2000,0..2000] OF LONGINT;
BEGIN
  WHILE NOT EOLN  
  DO
    BEGIN
      READ(Ch);
      IF Ch='1'
      THEN
        i := i+1;
    END;
  READLN;
  WHILE NOT EOLN
  DO
    BEGIN
      READ(Ch);
      IF Ch='1'
      THEN
        j := j+1;
    END;
  IF (j<=i) OR ((j=i+1) AND (i MOD 2=1))
  THEN
    WRITELN('YES')
  ELSE
    WRITELN('NO');
END.