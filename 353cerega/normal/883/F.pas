VAR
  a: ARRAY[0..100,1..500] OF CHAR;
  d, flag: ARRAY[1..500] OF LONGINT;
  N, k, ans, i, j: LONGINT;
BEGIN
  READLN(N);
  FOR k := 1 TO N DO
    BEGIN
    WHILE NOT EOLN
    DO
      BEGIN
        d[k] := d[k]+1;
        READ(a[d[k],k]);
        IF a[d[k],k]='u'
        THEN
          BEGIN
            a[d[k],k] := 'o';
            d[k] := d[k]+1;
            a[d[k],k] := 'o';
          END;
        IF a[d[k],k]='h'
        THEN
          BEGIN
            WHILE (d[k]>1) AND (a[d[k]-1,k]='k')
            DO
              BEGIN
              d[k] := d[k]-1;
              a[d[k],k] := 'h';
              END;
          END;
      END;
    READLN;
    END;
  FOR i := 1 TO N DO
    IF flag[i]=0
    THEN
      BEGIN
        ans := ans+1;
        FOR j := i+1 TO N DO
          IF d[i]=d[j]
          THEN
            BEGIN
              k := 1;
              WHILE (k<=d[i])
              DO
                BEGIN
                  IF a[k,i]<>a[k,j]
                  THEN
                    BREAK
                  ELSE
                    IF k=d[i]
                    THEN
                      flag[j] := 1;
                  k := k+1;
                END;
            END;
      END;
  WRITELN(ans);
END.