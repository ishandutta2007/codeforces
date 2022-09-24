VAR
  a, b, c, d, i, j, l1, l2: LONGINT;
  Res: INT64;
  M: ARRAY[0..10000] OF INT64;
  s, t: ARRAY[1..10000] OF CHAR;
BEGIN
  WHILE NOT EOLN
  DO
    BEGIN
      l1 := l1+1;
      READ(s[l1]);
    END;
  READLN;
  WHILE NOT EOLN
  DO
    BEGIN
      l2 := l2+1;
      READ(t[l2]);
    END;
  FOR i := 1 TO l1 DO
    M[i] := 1;
  FOR i := 1 TO l2 DO
    FOR j := l1 DOWNTO 1 DO
      BEGIN
        IF s[j]=t[i]
        THEN
          BEGIN
            Res := (Res+M[j]) MOD 1000000007;
            M[j+1] := (M[j+1]+M[j]) MOD 1000000007;
          END;
      END;
  WRITELN(Res);
END.